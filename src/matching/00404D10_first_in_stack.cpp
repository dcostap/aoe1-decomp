// PDB owner: RGE_Action_Missile::first_in_stack, ACT_misl.cpp lines 58-68.
// BINARY NOTE: The target-null and sentinel tests are one compound guard.
// This keeps one set_state(3) call site and the original fault order.
//
// 00404D10 RGE_Action_Missile::first_in_stack (62B)
// ACT_misl.cpp

#ifndef ACT_MISL_SHARED_CONTEXT
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Static_Object;
class RGE_Master_Action_Object;
class RGE_Task;

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
    unsigned char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    unsigned char gap_0D[3];
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
    unsigned char subActionValue;
    unsigned char gap_3D[3];
};

class RGE_Action_Missile : public RGE_Action {
public:
    virtual void first_in_stack(unsigned char value);
};
#endif

void RGE_Action_Missile::first_in_stack(unsigned char value) {
    if (value != 0) {
#ifdef ACT_MISL_SHARED_CONTEXT
        if (this->target_obj == 0 &&
            (*(int*)&this->target_x == 0xBF800000 ||
             *(int*)&this->target_y == 0xBF800000)) {
            set_state(1);
        } else {
            set_state(3);
        }
#else
        if (this->target_obj == 0 &&
            (*(int*)&this->target_x == 0xBF800000 ||
             *(int*)&this->target_y == 0xBF800000)) {
            set_state(1);
        } else {
            set_state(3);
        }
#endif
    } else {
        set_state(4);
    }
}
