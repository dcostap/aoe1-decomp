#ifndef ACT_OBJ_CONTEXT_H
#define ACT_OBJ_CONTEXT_H

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Action_Move_To;
class RGE_Active_Sprite_List;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Task_List;
class RGE_Tile;
class TDrawArea;
class UnitAIModule;
class LOSTBL;

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern "C" void __cdecl rge_write(int handle, void* buffer, int count);
extern float save_game_version;
extern FILE* actionFile;
extern void operator_delete(void* ptr);

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int, uchar);
    uchar master_type;
    char gap_05[0x0F];
    short object_group;
    char gap_16[0xA2];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    uchar size_class;
    char gap_C9;
    short obj_trail_id;
    uchar obj_trail_options;
    char gap_CD[3];
    float obj_trail_spacing;
    uchar move_algorithem;
    char gap_D5[3];
};

// The command surface inherits the target-task slot before getTask.
class RGE_Task_List {
public:
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*,
                                      float, float, float);
};

class RGE_Master_Command : public RGE_Task_List {
public:
    virtual RGE_Task* getTask(RGE_Action_Object* action, RGE_Static_Object* target,
                              float x, float y, float z);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual RGE_Task_List* create_task_list();
    RGE_Task_List* tasks;
    short default_task;
    char gap_DE[2];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    uchar task_by_group;
    char gap_ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    uchar run_pattern;
    char gap_F9[3];

    RGE_Task* get_task(short task_id);
    RGE_Task* getTaskByTaskID(int task_id);
};

class RGE_World {
public:
    virtual ~RGE_World();
    long world_time;
};

class RGE_Game_World : public RGE_World {
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_World* world;
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
    virtual void notify_of_relation(int, int);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(int);
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
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(void*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual int setup(RGE_Master_Action_Object*, RGE_Player*, float, float, float);
    virtual RGE_Action_List* create_action_list();

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
    void* player_object_node;
    char pathingGroupMembers[0x10];
    char groupMembers[0x10];
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
    uchar pad_87;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    virtual uchar update();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    RGE_Moving_Object(void* master, void* player, float x, float y, float z, int flag);
    RGE_Moving_Object(int id, RGE_Game_World* world, int flag);
    virtual int setup(RGE_Master_Action_Object*, RGE_Player*, float, float, float);
    int setup(int, RGE_Game_World*);
    void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    void save(int);
    void transform(RGE_Master_Static_Object*);
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    RGE_Action_Object(void* master, void* player, float x, float y, float z, int flag);
    RGE_Action_Object(int id, RGE_Game_World* world, int flag);
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
protected:
    virtual int setup(RGE_Master_Action_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);
    virtual RGE_Action_List* create_action_list();

public:
    virtual void rehook();
    virtual void save(int);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void destroy_obj();
    virtual void notify_of_relation(int, int);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual uchar update();
    virtual void set_attack(int);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_task(short);
    virtual void set_action(RGE_Action*);
    virtual void setTaskByTaskID(int);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual void stop();
    virtual void change_ownership(RGE_Player*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual uchar have_action();
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual uchar actionState() const;
    virtual long get_action_checksum();

    uchar waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
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
    virtual short action_id();
    virtual int can_work(RGE_Static_Object*, float, float, float);
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
    char gap_06[6];
    uchar state;
    char gap_0D[0x33];
};

class RGE_Action_Move_To : public RGE_Action {
public:
    char gap_40[4];
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, void*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, void*);
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();
    RGE_Action_Object* obj;
    void* list;
    RGE_Action_List(RGE_Action_Object*);
    void delete_list();
    void rehook();
    void save(int);
    void add_action(RGE_Action*);
    void add_action_at_end(RGE_Action*);
    int action_stop();
    int action_move_to(RGE_Static_Object*, float, float, float);
    int action_work(RGE_Static_Object*, float, float, float);
    RGE_Action* get_action();
    RGE_Task* get_task();
    uchar have_action();
    void remove_action();
    void copy_obj(RGE_Action_List*);
    void copy_obj(RGE_Master_Static_Object*);
    void load(int);
    RGE_Action* create_task_action_at(RGE_Task*, RGE_Static_Object*, float, float, float);
};

class RGE_Task {
};

class UnitAIModule {
public:
    void setCurrentOrder(int);
    void setCurrentAction(int);
    void setCurrentTarget(int, int, float, float, float);
    void setTaskedByPlayer();
};

#endif
