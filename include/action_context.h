#ifndef ACTION_CONTEXT_H
#define ACTION_CONTEXT_H

// Authentic action.cpp translation-unit context.
//
// Binary-supported ownership:
// - RGE_Action has its vptr at +0 and its data fields from +04 through +3F.
// - The action vtable uses the reviewed RGE_Action method order.  In
//   particular create_action_list is slot 3, and set_target_obj and
//   set_target_obj2 are slots 21 and 22.
// - RGE_Action_List stores its object at +04 and its node list at +08.
// - RGE_Action_Object stores master_obj, owner, and sprite at +08, +0C, and
//   +10.  RGE_Master_Action_Object::tasks is at +D8.
// - RGE_Task_List::list and list_num are at +04 and +08.
// - RGE_Static_Object notification calls use slots 48 and 49.
//
// This header supplies one compiler-facing class surface for the PDB-ordered
// owners.  It adds no function body, vtable write, padding owner, or register
// control.

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
struct RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Task_List;
class RGE_Game_World;
class RGE_Unit_Object_Owner;
class TDrawArea;

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char gap_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, short);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*,
                                      float, float, float);
    virtual int is_attack_task(RGE_Task*);
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);
    virtual ~RGE_Task_List();

    RGE_Task** list;
    short list_num;
    char gap_0A[2];
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    RGE_Task_List* tasks;
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*,
                                            float, float, float);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
    virtual void get_action_name(char*);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    ~RGE_Action_List();

    union {
        RGE_Action_Object* obj;
        int field_4;
    };
    union {
        RGE_Action_Node* list;
        int field_8;
    };

    RGE_Action_List(RGE_Action_Object*);
    void load(int);
    void save(int);
    void rehook();
};

class RGE_Static_Object {
public:
    // This is the authentic prefix of stat_obj.h's virtual surface.  The
    // action TU only calls the two slots at +0xC0 and +0xC4.
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
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
    virtual void remove_overlay_sprite(int);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned int);
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
    virtual void set_attribute_amount(float, unsigned char);
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

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Unit_Object_Owner* owner;
    RGE_Sprite* sprite;
    char gap_14[0x34];
    unsigned char object_state;

    RGE_Static_Object* get_object_pointer(long);
    RGE_Sprite* get_sprite_pointer(short);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int);
};

class RGE_Unit_Object_Owner {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Animated_Object : public RGE_Static_Object {};
class RGE_Moving_Object : public RGE_Animated_Object {};
class RGE_Action_Object : public RGE_Moving_Object {};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);

protected:
    virtual void set_state(unsigned char);

public:
    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    union {
        int targetID;
        int target_id;
    };
    union {
        int target2ID;
        int target2_id;
    };
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);
    float targetX() const;
    float targetY() const;
    float targetZ() const;
    unsigned char subAction() const;
    void setSubAction(unsigned char);
};

struct InnerObj {
    char gap_0[0x48];
    unsigned char field_48;
};

#endif
