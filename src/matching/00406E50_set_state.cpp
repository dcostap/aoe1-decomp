// RGE_Action_Transport::set_state
// VA: 00406E50
// PDB: act_tran.cpp:96-133
//
// Attempt log:
// - Reconstructed the transport/action ownership and constructor surface from
//   the exact act_tran.cpp siblings before probing VC5 codegen.
// - Replaced equivalent guards with a natural switch whose case order keeps
//   states 4/11 inline and state 2 in the late handler; exact under /GX.

class RGE_Sprite;

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual float teleport();
    virtual void new_sprite(RGE_Sprite* sprite);

    int gap_04;
    RGE_Master_Action_Object* master_obj;
};

class RGE_Action_List {
public:
    void delete_list(void);
    void add_action(class RGE_Action* action);
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int value);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(void* object, float x, float y, float z);
    virtual int work(void* object, float x, float y, float z);
    virtual unsigned char attack_response(void* object);
    virtual unsigned char relation_response(long value, unsigned char relation);
    virtual void copy_obj(void* object);
    virtual void copy_obj_sprites(void* object, RGE_Task* task, RGE_Task* other_task);
    virtual void get_state_name(char* name);
    virtual void* get_target_obj();
    virtual void* get_target_obj2();
    virtual void set_target_obj(void* object);
    virtual void set_target_obj2(void* object);
    virtual void set_state(unsigned char state);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
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

    void setSubAction(unsigned char value);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* object, float x, float y, float z,
                       float range, RGE_Sprite* sprite);

    float move_range;
};

class RGE_Action_Transport : public RGE_Action {
public:
    virtual void set_state(unsigned char state);
};

void RGE_Action_Transport::set_state(unsigned char param_1)
{
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 4:
    case 0x0B:
        if (this->task != 0) {
            move_to = new RGE_Action_Move_To(
                this->obj,
                this->target_x,
                this->target_y,
                this->target_z,
                0.3f,
                this->task->move_sprite
            );
        } else {
            move_to = new RGE_Action_Move_To(
                this->obj,
                this->target_x,
                this->target_y,
                this->target_z,
                0.3f,
                this->obj->master_obj->sprite
            );
        }

        if (move_to == 0) {
            this->set_state(2);
            return;
        }

        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }
}
