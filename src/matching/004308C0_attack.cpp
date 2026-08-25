// 004308C0 RGE_Combat_Object::attack(int target_id, int force)
// Attempt log:
// 1: Natural reconstruction from packet, modeled after matching 00430A90 attack(float,float,float,int); with /GX flag, close but initial object lookup used [this+0x0c] directly instead of owner->world.
// 2: Model +0x0c as owner/player with world at +0x3c, matching original first call and special group branch.
// FLAGS: config/flags/004308C0_attack.rsp uses /GX for original EH frame.

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    char gap_04[4];
    void* master; // +8
    char gap_0c[0x2c];
    float x; // +38
    float y; // +3c
    float z; // +40
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(void*);
    virtual int setup(int, void*);
    virtual void* create_action_list(void*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack();
    virtual void inside_obj_update();
    virtual void idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual void attack_response();
    virtual void relation_response();
    virtual void copy_obj();
    virtual void copy_obj_sprites();
    virtual void get_state_name();
    virtual RGE_Static_Object* get_target_obj();
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Owner {
public:
    char gap_00[0x24];
    void* table24;
    char gap_28[0x14];
    RGE_Game_World* world;
};

class RGE_Master_Combat_Object {
public:
    char gap_000[0x14];
    short object_group;
    char gap_016[0xfe];
    float field_114;
    char gap_118[0x0c];
    short field_124;
    char gap_126[4];
    short field_12a;
    char gap_12c[0x0c];
    float field_138;
};

class RGE_Action_Attack {
public:
    char gap_00[0x5c];
    RGE_Action_Attack(void* obj, RGE_Static_Object* target, int a, int b, int c, float f1, float f2, short s1, short s2);
};

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    void set_something(int);
    void add_action(RGE_Action_Attack* action);

    char gap_004[4];
    RGE_Master_Combat_Object* master; // +08
    RGE_Owner* owner; // +0c
    char gap_010[0x174];
    RGE_Action_List* action_list; // +184

    int attack(int target_id, int force);
};
#endif

int RGE_Combat_Object::attack(int target_id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(target_id);
    if (target == 0) {
        return 0;
    }

    if (force == 0) {
        if (this->action_list->have_action() == 1) {
            if (this->action_list->get_action()->get_target_obj() == target) {
                if (this->action_list->get_action()->type() == 9) {
                    return 1;
                }
                if (this->action_list->get_action()->type() == 7) {
                    return 1;
                }
            }
        }
    }

    if (this->action_list->have_action() == 1) {
        if (this->action_list->get_action()->get_target_obj() == target) {
            if (this->action_list->get_action()->type() == 9) {
                this->action_list->get_action()->work(target, target->x, target->y, target->z);
                return 1;
            }
        }
    }

    if (this->master->object_group == 4) {
        int value = *(int*)((char*)this->owner + 0x24);
        value = *(int*)((char*)value + 0x14c);
        if (value != 0) {
            this->set_something(value);
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, target, 0, 0, 0,
        this->master->field_114, this->master->field_138, this->master->field_124, this->master->field_12a);
    if (action == 0) {
        return 0;
    }
    this->action_list->delete_list();
    this->add_action(action);
    return 1;
}
