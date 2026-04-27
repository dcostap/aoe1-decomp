// attempt log:
// first pass: mirror the convert action work path from the packet and the RGE_Action donor slot order
// second pass: remove the explicit vtable field so the compiler's hidden vptr lines up with the dump layout
// third pass: keep the work path in the simplest nested-if form and let the vtable call shape fall out naturally
// paused here: the offsets are now right, but VC5 still prefers the wrong null-branch polarity / return-block layout
// target shape: null target => 0; same target plus state 4/6/7 => 1; otherwise set target, copy coords, and first_in_stack(1)

typedef unsigned char uchar;

class RGE_Static_Object {
public:
    char pad_00[0x38];
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
    short action_type;
    unsigned char _pad_0[0x2];
    RGE_Action_Object* obj;
    uchar state;
    unsigned char _pad_1[0x3];
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
    void* sprite;
    uchar subActionValue;
    unsigned char _pad_end[0x3];

    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(uchar param_1);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual uchar attack_response(RGE_Static_Object* param_1);
    virtual uchar relation_response(long param_1, uchar param_2);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(uchar param_1);
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    uchar was_same_owner;
    char gap_41[0x3];
    float requiredRange;

    int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

int TRIBE_Action_Convert::work(RGE_Static_Object* target, float param_2, float param_3, float param_4) {
    if (target != 0) {
        if (target == this->target_obj) {
            uchar state = this->state;
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

        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->first_in_stack(1);
        return 1;
    }

    return 0;
}
