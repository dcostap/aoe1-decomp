// VA: 004014B0 RGE_Action_Attack::first_in_stack
// Attempt log:
// - The former source used a naked inline-assembly body. This reconstruction
//   uses the proven action, object, and UnitAIModule member surfaces.
// - The target reuses the saved this home as rangeStatus after the first two
//   pushes. Keep rangeStatus as a local initialized immediately before the
//   ready_to_attack call.
// - BINARY NOTE: The shipped code loads EAX for state 13 and EDX for state 6.
//   The nested guard preserves this register order.
// - The generated exact form used ready_to_attack == 0, then tested
//   range_status == 1 before the state 6 return. The other path sets state 13.
// - The RGE_Action and RGE_Action_Object declarations now use canonical names,
//   inheritance, fields, and pointer types from the local class evidence.
// - Independent walkbacks of each canonical declaration family stayed exact.
//   The named forms remain because they satisfy source ownership policy.
// - VALIDATION: check_function.py --va 004014B0 --detail full => MATCH, 0.0000%.

#ifndef ACT_ATAK_CONTEXT_H
class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Color_Table;
class TDrawArea;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class UnitAIModule;

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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
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

    char gap_04[0x84];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    unsigned char waiting;
    unsigned char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;

    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap_04[0x24];
    int currentOrderValue;
    int currentOrder();
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
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
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
    unsigned char subActionValue;
    char gap_3D[3];
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual void first_in_stack(unsigned char param_1);

    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;
    unsigned char gap_5B;

    int ready_to_attack(int& range_status);
};
#endif

void RGE_Action_Attack::first_in_stack(unsigned char param_1)
{
    if (this->obj->maximumSpeed() != 0.0) {
        UnitAIModule* ai = this->obj->unitAI();
        if (ai == 0 || this->obj->unitAI()->currentOrder() != 0x2D5) {
            this->set_state(4);
            return;
        }
    }

    int range_status = -1;
    if (this->ready_to_attack(range_status) == 0) {
        if (range_status == 1) {
            this->set_state(6);
            return;
        }
        this->set_state(0x0D);
        return;
    }
    this->set_state(6);
}
