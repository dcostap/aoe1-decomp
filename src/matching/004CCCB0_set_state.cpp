// VA: 004CCCB0 TRIBE_Action_Artifact::set_state
// tact_art.cpp lines 78-116

// attempt 1: natural C++ with 'new' expression + ctor, /GX flag; the old
// reconstruction used an if/else chain and the wrong task/action parameter
// surfaces, so it emitted byte compares and non-original relocations.
// The executable's sub/dec/sub dispatch and constructor metadata support a
// switch over the original state, with task->move_sprite and RGE_Action* ABI.
// attempt 2: source-order switch (10, 4, 5) restored the original dispatch,
// block topology, and exact 0x138-byte function size.
// attempt 3: the proven RGE_Action 0x40 base and Move_To range at +0x40
// restored the 0x44 allocation size; typed task/target fields preserve the
// constructor's named ownership without raw offset plumbing.
// attempt 4: corrected RGE_Action_List::add_action and Move_To sprite
// parameter ABIs; exact bytes under config/flags/004CCCB0_set_state.rsp.

#ifndef AOE1_TACT_ART_TU_CONTEXT
class RGE_Action;
class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Action_List {
public:
    void delete_list();
    void add_action(RGE_Action* action);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int id, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long player, unsigned char relation);
    virtual void copy_obj(void* master_action);
    virtual void copy_obj_sprites(void* master_action, RGE_Task* task1, RGE_Task* task2);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);
    short action_type;             // +0x04
    char gap_06[2];                // +0x06
    RGE_Action_Object* object;     // +0x08
    unsigned char state;           // +0x0C
    char gap_0D[3];                // +0x0D
    RGE_Static_Object* target_obj; // +0x10
    RGE_Static_Object* target_obj2;// +0x14
    int target_id;                 // +0x18
    int target2_id;                // +0x1C
    float target_x;                // +0x20
    float target_y;                // +0x24
    float target_z;                // +0x28
    float timer;                   // +0x2C
    RGE_Task* task;                // +0x30
    RGE_Action_List* sub_actions;  // +0x34
    RGE_Sprite* sprite;            // +0x38
    unsigned char sub_action_value;// +0x3C
    char gap_3D[3];                // +0x3D
};

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;                 // +0x38
    float world_y;                 // +0x3C
    float world_z;                 // +0x40
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;       // +0x34
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;                  // +0x40
    RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z, float speed, RGE_Sprite* sprite);
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    virtual void set_state(unsigned char new_state);
};
#endif

void TRIBE_Action_Artifact::set_state(unsigned char new_state) {
    this->state = new_state;
    switch (new_state) {
    case 10:
        timer = 3.0f;
        break;
    case 4: {
        sub_actions->delete_list();
        RGE_Action_Move_To* move = new RGE_Action_Move_To(object, target_x, target_y, target_z, 0.0f,
            task->move_sprite);
        if (move != 0) {
            sub_actions->add_action(move);
            this->set_state(6);
        }
        break;
    }
    case 5: {
        sub_actions->delete_list();
        target_x = target_obj->world_x;
        target_y = target_obj->world_y;
        target_z = target_obj->world_z;
        target_obj = 0;
        RGE_Action_Move_To* move = new RGE_Action_Move_To(object, target_x, target_y, target_z, 0.0f,
            task->move_sprite);
        if (move != 0) {
            sub_actions->add_action(move);
            this->set_state(6);
        }
        break;
    }
}
}
