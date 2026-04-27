// first pass: null target gate, same-target/state fast path, then update target and coordinates before first_in_stack(1)
// close sibling 004CE450 suggests the natural RGE_Action surface plus direct virtual-slot calls is the right basin here
// tried direct virtual calls and manual vtable calls; the remaining mismatch is in the call/push-cleanup basin, not the target/state/coordinate logic
class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    char pad_08[0x30];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;
class RGE_Master_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char attack_response(RGE_Static_Object* param_1);
    virtual unsigned char relation_response(long param_1, unsigned char param_2);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    short action_type;             // +0x4
    unsigned char _pad_0[0x2];     // +0x6
    void* obj;                     // +0x8
    unsigned char state;           // +0xC
    unsigned char _pad_1[0x3];     // +0xD
    RGE_Static_Object* target_obj; // +0x10
    RGE_Static_Object* target_obj2;// +0x14
    int targetID;                  // +0x18
    int target2ID;                  // +0x1C
    float target_x;                // +0x20
    float target_y;                // +0x24
    float target_z;                // +0x28
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    int work(RGE_Static_Object* target, float param_2, float param_3, float param_4);
};

int TRIBE_Action_Heal::work(RGE_Static_Object* target, float param_2, float param_3, float param_4) {
    if (target == 0) {
        return 0;
    }

    if (target == this->target_obj) {
        unsigned char state = this->state;
        if (state == 4) {
            return 1;
        }
        if (state == 6) {
            return 1;
        }
        if (state == 7) {
            return 1;
        }
    }

    void** vtbl = *(void***)this;
    ((void (*)(RGE_Action*, RGE_Static_Object*))vtbl[0x54 / 4])((RGE_Action*)this, target);
    this->target_x = target->world_x;
    this->target_y = target->world_y;
    this->target_z = target->world_z;
    ((void (*)(RGE_Action*, unsigned char))vtbl[0x1C / 4])((RGE_Action*)this, 1);
    return 1;
}
