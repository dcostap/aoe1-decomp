#ifndef AOE1_COM_OBJ_CONTEXT_H
#define AOE1_COM_OBJ_CONTEXT_H

// Module-local declaration surface for com_obj.cpp.
// Virtual names and slots follow the shipped RGE_Static_Object,
// RGE_Combat_Object, RGE_Player, and UnitAIModule listings in
// orig/aoe1_ghidra_assembly_listing.txt.
// All com_obj owners include this one declaration surface.

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;
class RGE_Master_Combat_Object;
class InnerObj;
class InnerObj_00431490;
class RGE_Combat_Object_State;
struct VISIBLE_UNIT_REC;
class RGE_Action;
class RGE_Action_List;
class RGE_Task;
class RGE_Sprite;
class RGE_Sound;
struct RGE_Armor_Weapon_Info;
class RGE_Tile;
class RGE_Map;
struct Link;
struct MapCell;
struct MapRow;
class RGE_Base_Object;
class UnitAIModule;
class Visible_Unit_Manager;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class TDrawArea;
class RGE_Color_Table;
class LOSTBL;
class Path;
struct XYPoint;
struct XYZPoint;
struct XYZBYTEPoint;
template<class T> class ManagedArray;

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern "C" float save_game_version;
extern "C" float g_attack_modifier;
extern "C" float DAT_0056f49c;
extern "C" float DAT_0056f4ac;
extern "C" int __cdecl debug_rand(const char*, int);

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x10];
    float** terrains;
    char gap_58[0x2C];
    float frame_delta;
    RGE_Static_Object* object(int index);
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    short map_width;
    short map_height;
    int is_player_turn(int);
    unsigned long get_accum_time_delta(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status();
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void aiStatus();
    virtual void isEnemy();
    virtual void isAlly();
    virtual void isNeutral();
    virtual void isAllNeutral();
    virtual void setDiplomaticStance();
    virtual void loadAIInformation();
    virtual void sendUnitAIOrder();
    virtual void processAIOrder();
    virtual void kickAI();
    virtual void strategicNumber();
    virtual void sendGameOrder();
    virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand();
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual void sendAICommand();
    virtual void objectCostByType();
    virtual void trackUnitGather();
    virtual void make_scenario_obj();
    virtual void scenario_save();
    virtual void scenario_load();
    virtual void scenario_postsave();
    virtual void scenario_postload();
    virtual void load();
    virtual void add_attribute_num();
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save();
    virtual void save2();
    virtual void save_info();
    virtual void random_start();
    virtual void make_new_object();
    virtual void analyize_selected_objects();
    virtual void get_mouse_pointer_action_vars();
    virtual void command_make_move();
    virtual void command_make_work();
    virtual void command_make_do();
    virtual void command_stop();
    virtual void command_place_object();
    virtual void command_add_attribute();
    virtual void command_give_attribute();
    virtual void command_formation();
    virtual void command_stand_ground();
    virtual void command_create_group();
    virtual void command_add_to_group();
    virtual void command_remove_from_group();
    virtual void command_destroy_group();
    virtual void command_resign();
    virtual void command_add_waypoint();
    virtual void addObject();
    virtual void removeObject();
    virtual void logMessage();
    virtual void notify(int, int, int, long, long, long);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    RGE_Master_Static_Object** master_objects;
    int computerPlayer();
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
    char gap_04[0x10];
    short object_group;
    char gap_16[0x10];
    union { short hp_short; short hp; };
    char gap_28[8];
    union { float radius_x; float range_30; };
    union { float radius_y; float range_34; };
    char gap_38[0x53];
    unsigned char area_effect_object_level;
    char gap_8C[0x70];
    RGE_Sprite* fight_sprite;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {};
class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {};
class RGE_Master_Action_Object : public RGE_Master_Moving_Object {};
class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    // Binary layout note: com_obj reads the armor table at +0x100..+0x10C
    // and the combat ranges at +0x114..+0x148.
    unsigned char base_armor;
    unsigned char gap_101;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char gap_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    union { char gap_110[4]; short defense_terrain_bonus; };
    union {
        float weapon_range;
        float field_114;
    };
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char gap_11E[2];
    float speed_of_attack;
    union { short missile_id; short field_124; };
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char pad_129;
    union {
        float weapon_offset_x;
        struct { union { short field_12a; short field_12A; }; short gap_12c; };
    };
    float weapon_offset_y;
    float weapon_offset_z;
    union { float minimum_weapon_range; float field_138; };
    union { char gap_13C[2]; short orig_armor; };
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;
    RGE_Sprite* moving_sprite;
    RGE_Sprite* sprite;
};

struct RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
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
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
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
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int, int);
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
    // Binary layout note: these aliases are shared offsets, not owner views.
    union { int id; int object_id; int field_04; int value_4; };
    union {
        RGE_Master_Combat_Object* master_obj;
        RGE_Master_Combat_Object* master;
        void* object_info;
        void* field_08;
        RGE_Combat_Object_State* state;
    };
    union { RGE_Player* owner; RGE_Player* player; void* field_0C; };
    RGE_Sprite* sprite;
    char gap_14[8];
    RGE_Tile* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    union { float x; float world_x; };
    union { float y; float world_y; };
    union { float z; float world_z; };
    union { float attribute_amount_held; float field_40; };
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    float angle;
    RGE_Player* action_player;
    char gap_58[0x1C];
    union { UnitAIModule* aiModule; UnitAIModule* unitAIValue; };
    char gap_78[0x10C];
    union { RGE_Action_List* actions; RGE_Action_List* action_list; };
    char gap_188[0x0C];
    VISIBLE_UNIT_REC* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    uchar capture_flag;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
};
class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
};

class RGE_Action_List {
public:
    uchar have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(uchar);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual uchar attack_response(RGE_Static_Object*);
    virtual uchar relation_response(long, uchar);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    uchar state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    uchar subActionValue;
    char gap_3D[3];
    float targetX();
    float targetY();
    float targetZ();
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    RGE_Action_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int);
    RGE_Action_Object(int, RGE_Game_World*, int);
    virtual int setup(int, RGE_Game_World*);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    int setup(RGE_Master_Action_Object*, RGE_Player*, float, float, float);
    virtual RGE_Action_List* create_action_list();
    void add_action(RGE_Action*);
    void play_move_sound();
    RGE_Task* make_enter_task(RGE_Static_Object*, int, int, int);
    RGE_Task* create_gather_task(RGE_Static_Object*, int, int, int);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    RGE_Combat_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int);
    RGE_Combat_Object(int, RGE_Game_World*, int);
    virtual ~RGE_Combat_Object();
protected:
    virtual int setup(int, RGE_Game_World*);
public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void save(int);
    virtual void stop();
    virtual uchar area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual uchar attack(float, float, float, RGE_Combat_Object*);
    virtual uchar attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual uchar do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual uchar can_attack();
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual void enter_obj(RGE_Static_Object*);
    virtual uchar update();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(int, int);
    virtual int attack(float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int gather(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int transport(float, float, float, int);
    virtual int unload(int, float, float, float);
    virtual int stopAction();
    virtual int pause();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float rateOfFire();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual float teleport(float, float, float);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    void reset_attack_timer();
    void get_weapon_range(short&, short&);
    void calc_attack_modifier();
    virtual void change_ownership(RGE_Player*);
    void set_something(int);
    virtual void new_sprite(RGE_Sprite*);
    virtual void play_move_sound(RGE_Sound*);
    float distance_to_object(RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
protected:
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    float base_teleport(float, float, float);
    unsigned char attack(RGE_Static_Object*, float, RGE_Combat_Object*, float, float);
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
};
class RGE_Action_Gather : public RGE_Action {
public:
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
};
class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(void*, void*, float, float, float);
};
class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(RGE_Action_Object*, RGE_Task*, float, float, float);
    int work(RGE_Static_Object*, float, float, float);
};
class RGE_Action_Move_To : public RGE_Action {
public:
    int pad_40;
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(void*, RGE_Static_Object*, float, void*);
};
class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(void*, RGE_Static_Object*, int, int, int, float, float, short, short);
    RGE_Action_Attack(void*, float, float, float, void*, void*, void*, float, float, short, short);
};

class RGE_Task {
};
class InnerObj {
public:
    int field_114;
    int field_120;
    int field_140;
    int field_144;
};
class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object*, RGE_Static_Object*, float);
    void init_missile(RGE_Combat_Object*, float, float, float, float);
};
class RGE_Base_Object : public RGE_Combat_Object {
public:
    static void enter_obj(RGE_Static_Object*);
};
struct MapCell {
    char gap[0x10];
    Link* objects;
    char gap_end[4];
};
struct MapRow {
    MapCell cell[1];
};
class RGE_Base_Game {
public:
    float calc_attack_modifier(int);
};
class RGE_Map {
public:
    char gap_00[8];
    short width;
    char gap_0A[2];
    short height;
    char gap_0E[0x8D7E];
    MapRow** rows;
};
class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
};
class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual void owner();
    virtual void order();
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
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
    void update(unsigned long);
};
class Visible_Unit_Manager {
public:
    void Update_Unit_Info(int, int, int, int, int, unsigned long, int, void*);
    void remove_object(RGE_Static_Object*);
};
class RGE_Object_List {
};
class RGE_Active_Sprite_List {
};
class RGE_Combat_Object_State {
public:
    char gap_00[0x18];
    int value_18;
};
struct VISIBLE_UNIT_REC {
    unsigned char gap_00[6];
    unsigned char pos_x;
    unsigned char pos_y;
};
class InnerObj_00431490 {
public:
    float rateOfFire;
    float weaponRange;
    float minimumWeaponRange;
};

extern UnitAIModule* unitAIValue;
extern Visible_Unit_Manager* VisibleUnitManager;

#endif
