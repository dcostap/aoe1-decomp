#ifndef ACT_MISL_CONTEXT_H
#define ACT_MISL_CONTEXT_H

// Canonical ACT_misl.cpp declaration surface.  The layout and virtual slots
// below are shared by the module's owners; they are not a general game ABI.

extern float DAT_0056e380;
extern double DAT_0056e388;
extern float DAT_0056e390;
extern float DAT_0056e394;
void __cdecl rge_read(int file, void* buffer, int size);
void __cdecl rge_write(int handle, const void* buffer, int size);

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Missile_Object;
class RGE_Action_List;
class RGE_Task;
class RGE_Sprite;
class RGE_Master_Action_Object;
class RGE_Game_World;
class RGE_Player;
class RGE_Moving_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class TDrawArea;
class LOSTBL;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    uchar master_type;
    uchar gap_05[0x0B];
    short id;
    uchar gap_12[0x26];
    float radius_z;
    uchar gap_3C[0x7C];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    uchar gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    uchar gap_D8[0x24];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    uchar gap_FC[0x4C];
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    uchar missile_type;
    uchar targetting_type;
    uchar missile_hit_info;
    uchar missile_die_info;
    uchar area_effect_specials;
    uchar gap_14D[3];
    float ballistics_ratio;
};

class RGE_Game_World {
public:
    uchar gap_00[0x84];
    float world_time_delta_seconds;
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    uchar gap_00[0x3C];
    RGE_Game_World* world;
    uchar gap_40[0x0A];
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
    virtual void set_attack();
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
    virtual int canPath(int, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(int, float, int, float*, int, int, int, int, int);
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
    virtual void* create_object_list();
    virtual void* create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
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
    uchar gap_50[0x38];

    uchar is_dying();
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);

    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    uchar gap_9C[0xE4];

    void set_velocity(float, float, float);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
    virtual void setTaskByTaskID(short);
    virtual void set_action(void*);
    virtual void set_only_action(void*);
    virtual void set_end_action(void*);
    virtual RGE_Task* getTask();
    virtual int setup(int, RGE_Game_World*);
    virtual RGE_Action_List* create_action_list();

    uchar waiting;
    uchar gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    uchar gap_189[3];
    int lastActionValue;
    int lastActionStateValue;

    float distance_to_object(RGE_Static_Object*);
    float distance_to_position(float, float, float);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual uchar area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual uchar attack(float, float, float, RGE_Combat_Object*);
    virtual uchar attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual uchar do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);

    uchar gap_1C4[0x30];
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    virtual int setup(RGE_Master_Missile_Object*, RGE_Player*, float, float, float);

    float max_range;

    uchar missile_move();
    class RGE_Check_List* make_object_collision_list(float);
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
    uchar gap_06[2];
    RGE_Action_Object* obj;
    uchar state;
    uchar gap_0D[3];
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
    uchar gap_3D[3];

    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, RGE_Action_Object*, int);
};

class RGE_Action_Missile : public RGE_Action {
public:
    virtual uchar update();
    virtual void save(int);

    float velocity_x;
    float velocity_y;
    float velocity_z;
    float ballistic_velocity;
    float ballistic_acceleration;

    RGE_Action_Missile(int, RGE_Action_Object*);
    RGE_Action_Missile(RGE_Action_Object*, RGE_Static_Object*, RGE_Static_Object*,
                       float, float, float);
    void first_in_stack(uchar);

protected:
    virtual void set_state(uchar);
    void intercept(float&, float&, float&);
};

struct RGE_Check_Node {
    RGE_Static_Object* object;
    float dx;
    float dy;
    uchar flag;
    uchar gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
};

#endif
