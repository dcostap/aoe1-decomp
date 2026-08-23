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
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual uchar update();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual float teleport(float, float, float);
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void die_die_die();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual uchar can_attack();
    virtual void vf80();
    virtual void vf84();
    virtual int vf88(int, int);
    virtual uchar vf8C(float);
    virtual int vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void new_angle(float);
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual uchar is_moving();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual float vfF0(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int vf114(float, float, int);
    virtual uchar vf118();
    virtual int vf11C();
    virtual float vf120();
    virtual float vf124();
    virtual float vf128();
    virtual void vf12C(uchar);
    virtual uchar vf130();
    virtual uchar vf134();
    virtual uchar vf138(int);
    virtual uchar vf13C(int);
    virtual uchar vf140();
    virtual void vf144(const char*, ...);
    virtual void vf148(int, int, int, long, long, long);
    virtual int vf14C(float, float, float, int);
    virtual int vf150(int, int);
    virtual int vf154(float, float, float, float, int);
    virtual int vf158(int, float, int);
    virtual int vf15C(int, int);
    virtual int vf160(int, int);
    virtual int vf164(int, int);
    virtual int vf168(int, int);
    virtual int vf16C(int, int);
    virtual int vf170(int, int);
    virtual int vf174(int, int);
    virtual int vf178(int, int);
    virtual int vf17C(int, int);
    virtual int vf180(int, int);
    virtual int vf184(int, float, float, float);
    virtual int vf188(float, float, float, int);
    virtual int vf18C();
    virtual int vf190();
    virtual int vf194(int, float, float*, int, int, int);
    virtual int vf198(int, float, int, float*, int, int, int);
    virtual int vf19C(int, int, float, float*, int, int, int);
    virtual int vf1A0(int, float, float*, int, int, int, void*);
    virtual int vf1A4(int, float, int, float*, int, int, int, int, int);
    virtual int vf1A8(int, float*, float*);
    virtual int vf1AC(int, int, int, int, float, int);
    virtual int vf1B0(void*, void*, float, void*, int);
    virtual int vf1B4(void*, void*, void*, int, int, int);
    virtual void* vf1B8(int);
    virtual int vf1BC(void*, int);
    virtual void vf1C0(int);
    virtual void vf1C4(int);
    virtual int vf1C8();
    virtual void* vf1CC(void*, float, int);
    virtual long vf1D0();
    virtual long vf1D4();
    virtual int vf1D8(int, RGE_Game_World*);
    virtual int vf1DC(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* vf1E0();
    virtual void* vf1E4();

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
