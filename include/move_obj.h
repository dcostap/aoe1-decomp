#ifndef MOVE_OBJ_H
#define MOVE_OBJ_H

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Sprite;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Tile;
class RGE_Object_List;
class RGE_Master_Static_Object;
class RGE_Master_Moving_Object;
class RGE_Static_Object;
class RGE_Moving_Object;
class UnitAIModule;
class NotifyEvent;
class OrderEvent;
class RGE_Visible_Map;
class AIPlayStatus;

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad[3];
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    void zeroNumber() { this->numberValue = 0; }
};

template<class T> class ManagedArray;

struct XYPoint {
    int x;
    int y;
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

class RGE_Zone_Map;

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(float*, long, int&);
    RGE_Zone_Map* get_zone_map(long);
};

class RGE_Zone_Map {
public:
    unsigned char get_zone_info(long, long);
    int withinRange(XYPoint, XYPoint, float);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
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
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
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
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

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
    ManagedArrayInt attackingUnitsValue;
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
    unsigned char pad_131[3];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;
    int map_height;
    char gap_10[0x8DB4];
    RGE_Zone_Map_List* map_zones;
    unsigned char get_terrain(short, short);
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    Path();
    Path(int);
    ~Path();
    Path& operator=(const Path&);
    void append(Waypoint);
    void insertAtEnd(Waypoint);
    void reset();
    void add_default();
    void inittostart();
    void movetonextwaypoint();
    void setTimeStamp(unsigned long);
    void killPath();
    int insertAtCurrent(Waypoint*);
    int insertAtCurrent(const Waypoint&);
    void initToStart();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
    Waypoint* lastWaypoint();
    const Waypoint* waypoint(int) const;
    int currentWaypointNumber();
    void setCurrentWaypointNumber(int);
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

    unsigned char master_type;
    unsigned char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char pad_16[2];
    RGE_Sprite* default_sprite;
    char gap_1C[0x14];
    float radius_x;
    float radius_y;
    float radius_z;
    short terrain;
    char gap_3E[0x7A];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    unsigned char pad_C9;
    short obj_trail_id;
    unsigned char obj_trail_options;
    unsigned char pad_CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    unsigned char pad_D5[3];
};

class RGE_Static_Object {
public:
    // BINARY NOTE: stopObject is a UnitAIModule slot, not a static-object slot.
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
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
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
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
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
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
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>&);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZBYTEPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* create_object_list();
    virtual void* create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
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
    void* player_object_node;
    ManagedArrayInt pathingGroupMembers;
    ManagedArrayInt groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char pad_87;

    unsigned char lookupZone(int, int);
    float get_terrain_speed(unsigned char);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    virtual void transform(RGE_Master_Static_Object*);
    RGE_Animated_Object(RGE_Master_Animated_Object*, RGE_Player*, float, float, float, int);
    RGE_Animated_Object(int, RGE_Game_World*, int);
    int setup(int, void*);
    int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;
    Path exceptionPathValue;
    Waypoint startValue;
    Waypoint goalValue;
    float turnTimer;
    float collisionAvoidanceDistance;
    float actionRange;
    int targetIDValue;
    float targetRadiusX;
    float targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;
    unsigned char storePathInExceptionPath;
    unsigned char waitingToMoveValue;
    unsigned char numberWaitDelays;
    unsigned char pad_157;
    int minInitialPointX;
    int minInitialPointY;
    int maxInitialPointX;
    int maxInitialPointY;
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char pad_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;
    unsigned char pad_17E[2];

    enum PathResult {
        PathFound = 0,
        PathNoPath = 1,
        NoPathFound = 1,
        WaitingOnPathingCap = 2
    };

    virtual float teleport(float, float, float);
    RGE_Moving_Object(RGE_Master_Moving_Object*, RGE_Player*, float, float, float, int);
    RGE_Moving_Object(int, RGE_Game_World*, int);
    virtual ~RGE_Moving_Object();
    void destroy();
protected:
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
public:
    void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    void save(int);
    void new_sprite(RGE_Sprite*);
    RGE_Static_Object* spawn_death_obj();
    void transform(RGE_Master_Static_Object*);
    unsigned char is_moving();
    virtual void stop_moving();
    int movement_state() const;
    virtual unsigned char waitingToMove() const;
    float angle_to_object(RGE_Static_Object*, float, float);
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    void set_velocity(float, float, float);
    void new_angle(float);
    const Path& getPath() const;
    virtual unsigned char facetToNextWaypoint() const;
    void setGoal(float, float, float);
    void setActionRange(float);
    void setTargetID(int);
    void setTargetRadius(float, float);
    virtual void setWaitingToMove(unsigned char);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    void setFinalUserDefinedWaypoint();
    void setInitialPoints(XYPoint&, XYPoint&);
    void copy_obj(RGE_Master_Static_Object*);
    virtual void rotate(long);
    virtual long get_waypoint_checksum();
    void boundAngle(float*, int);
    void set_angle();
    int doTrivialMove(float, float);
    int doMove();
    PathResult findPath();
    virtual Path* findAvoidancePath(XYZPoint&, float, int);
    virtual int passableTile(float, float, int);
    virtual float maximumSpeed();
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>&);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(const XYPoint&, const XYPoint&, float, XYPoint&, int);
    virtual int firstTileAlongLine(const XYPoint&, const XYPoint&, XYPoint&, int, int, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    void setStart(float, float, float);
    void displayPath(int);
};

class RGE_Sprite {
public:
    char gap_00[0x60];
    short facet_num;
    char gap_62[2];
    float base_speed;
    char gap_68[8];
    unsigned char flag;
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    char gap_18[0x6C];
    float world_time_delta_seconds;
    RGE_Map* map;
    char gap_2C[0x24];
    short terrain_num;
    short terrain_size;
    float** terrains;

    RGE_Static_Object* object(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    char gap_40[0x1E0];

    int availablePathingAttempts(unsigned char);
    void incrementPathingAttempts();
    int computerPlayer();
};

class PathingSystem {
public:
    void incrementInitialPaths();
    void incrementContinuePaths();
    void incrementCanPaths();
    void copyUnobstructibles(ManagedArray<int>&);
    void initMisc(unsigned char);
    int findTilePath(int, int, int, int, RGE_Moving_Object*, float, int,
                     int, float*, int, int, int, int, int, int);
    int passable(RGE_Moving_Object*, float, float, int);
};

extern PathingSystem aiPathSystem;
extern PathingSystem pathSystem;
extern FILE* actionFile;
extern int displayPathingFlags;
extern int displayPathObjectID;

extern double DAT_00570B40;
extern float DAT_00570B48;
extern float DAT_00570B4C;
extern float DAT_00570B50;
extern float DAT_00570B60;
extern float DAT_00570B64;
extern double DAT_00570B68;
extern double DAT_00570B70;
extern float DAT_00570B78;
extern float DAT_00570B80;
extern float DAT_00570B84;
extern float DAT_00570B88;
extern double DAT_00570B90;
extern double DAT_00570B98;
extern float DAT_00570BA0;
extern float DAT_00570BA8;
extern double DAT_00570BB0;
extern double DAT_00570BB8;
extern float DAT_00570BC0;
extern double DAT_00570BC8;
extern double DAT_00570BD0;
extern double DAT_00570BE0;
extern double DAT_00570BF0;
extern float DAT_00570BFC;
extern double DAT_00570C00;

extern "C" int __cdecl debug_rand(char*, int);

#endif
