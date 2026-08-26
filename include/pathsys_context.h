#ifndef PATHSYS_CONTEXT_H
#define PATHSYS_CONTEXT_H

#include <stdio.h>

class RGE_Action_Object;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class RGE_Sprite;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class RGE_Object_Node;
class UnitAIModule;
class TDrawArea;
class RGE_Color_Table;
struct RGE_Tile;

// Canonical period ABI for the pathsys.cpp owner group.
// The fields below use the binary-proven offsets used by the path search,
// obstruction, and path-copy owners.  This header is only the module context;
// owner bodies remain in their source-bank files.

typedef unsigned char uchar;
typedef unsigned int uint;

extern void operator delete(void* ptr);
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);
extern void* operator new(unsigned int size, void* ptr);
extern int DiagionalDistance[256];

struct XYPoint {
    int x;
    int y;
};

struct BYTEPoint {
    uchar x;
    uchar y;
};

struct Waypoint {
    float x;
    float y;
    float z;
    uchar facetToNextWaypoint;
    uchar pad[3];
};

struct MGP_FloatHeap {
    uchar x;
    uchar y;
    unsigned short next;
    int total;
};

struct PathTileWork {
    XYPoint current;
    XYPoint next;
    XYPoint copied;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}

    ~ManagedArray() {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    int add(T val) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == val)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int new_size = this->numberValue + 1;
            T* new_data = (T*)operator_new(new_size * sizeof(T));
            if (new_data != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_data[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }

    T& operator[](int index) {
        return this->value[index];
    }
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

    void killPath();
    void initToStart();
    int insertAtCurrent(const Waypoint& waypoint);
};

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void redraw(int mode);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual RGE_View* get_view();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    uchar master_type;
    uchar pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    uchar pad_16[0x10];
    float los;
    uchar obj_max;
    uchar pad_2d[3];
    float radius_x;
    float radius_y;
    float radius_z;
    uchar pad_3c[0x2A];
    short terrain;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    uchar pad_14[0x36];
    short id;

    int computerPlayer();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*,
                                                         float, float, float);
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
    uchar pad_end;

    int removeFromObstructionMap(int aiPS);
    int addToObstructionMap(int aiPS);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
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
    uchar storePathInExceptionPath;
    uchar waitingToMoveValue;
    uchar numberWaitDelays;
    uchar pad_157;
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;
    void* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    uchar finalUserDefinedWaypoint;
    uchar pad_175[3];
    float closestDistanceToWaypoint;
    uchar lastFacet;
    uchar lastFacet2;
    uchar pad_17e[2];

    void setInitialPoints(XYPoint* minp, XYPoint* maxp);
    virtual void __cdecl print(char* format, ...);
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type;
    uchar border_type;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    char objects[0x0C];
};

struct RGE_Border_Set {
    uchar pad_000[0x59C];
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    union {
        int width;
        int map_width;
    };
    union {
        int height;
        int map_height;
    };
    int world_width;
    int world_height;
    uchar pad_18[0x338C - 0x18];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    uchar pad_04[0x50];
    float** terrains;

    int objectGroupOnTile(int playerId, int objectGroup, int tileX, int tileY,
                          int* objectCountOnTile);
    int objectGroupOnTile(int playerId, int objectGroup, int tileX, int tileY,
                          int& objectCountOnTile);
    RGE_Static_Object* object(int id);
};

class PathingSystem {
public:
    virtual ~PathingSystem();

    int xSizeValue;
    int ySizeValue;
    uchar facetValue[255][255];
    uchar pad_fe0d[3];
    int MGP_costValue[255][255];
    MGP_FloatHeap MGP_openPaths[65026];
    union {
        uchar obstructionValue[1020][255];
        uchar obstructionValueFlat[1020 * 255];
    };
    uchar miscValue[255][255];
    uchar pad_11dc29[3];

    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    RGE_Map* mapValue;
    RGE_Game_World* worldValue;
    RGE_Moving_Object* currentObject;
    int currentObjectInObMap;
    int currentTargetID;
    float* currentTerrainTable;
    float currentXOffset;
    float currentYOffset;
    int currentTerrainException1;
    int currentTerrainException2;

    ManagedArray<int> initialCollidingObjects;
    int startOfPath;
    int checkTerrainOnFirstPass;
    XYPoint initialTile;
    XYPoint minTarget;
    XYPoint maxTarget;
    XYPoint minInitialPosition;
    XYPoint maxInitialPosition;
    float averageNumWaypoints;
    float averagePathLength;
    float averagePathIterations;
    int numAttempts;
    int numFails;
    int numSuccesses;
    union {
        int numInitialPathsValue;
        int field_11DCBC;
    };
    union {
        int numContinuePathsValue;
        int field_11DCC0;
    };
    union {
        int numCanPathsValue;
        int field_11DCC4;
    };
    int MGP_closestTargetDistance;
    float averageClosestTargetDistance;
    float averageSuccessTime;
    float averageFailTime;
    uchar CurrentFacetMask;
    uchar pad_11dcd9[3];
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray<int> currentUnobstructibles;
    int aiPS;

    PathingSystem(int xSize, int ySize, int aiPS, RGE_Map* map,
                  RGE_Game_World* world);
    int initialize(int xSize, int ySize, RGE_Map* map, RGE_Game_World* world);
    void initMisc(unsigned char value);
    void zeroObstructionMap();
    unsigned char lookupMisc(int row, int column);
    void setMisc(int row, int column, unsigned char value);
    unsigned char obstruction(int x, int y);
    void incrementObstruction(int x, int y);
    void decrementObstruction(int x, int y);
    int findTilePath(int startX, int startY, int goalX, int goalY,
                     RGE_Moving_Object* obj, float tolerance, int targetID,
                     int mode, float* costOut, int useIterationCap,
                     int checkTerrain, int checkObstructions, int step,
                     int unobPlayerID, int unobGroupID);
    void incrementInitialPaths();
    void incrementContinuePaths();
    void incrementCanPaths();
    int passable(RGE_Moving_Object* object, float x, float y, int checkObjects);
    long checksum(void);
protected:
    void printState(RGE_Moving_Object* obj);
public:
    int copyPath(int step);
    void copyUnobstructibles(ManagedArray<int>& out);
    void printToFile(char* filename);
};

class RGE_Path_Finder {
public:
    void incrementInitialPaths();
    void incrementContinuePaths();
    void incrementCanPaths();
};

extern PathingSystem pathSystem;
extern PathingSystem aiPathSystem;

#endif
