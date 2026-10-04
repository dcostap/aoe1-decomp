#ifndef AOE1_ACTION_H
#define AOE1_ACTION_H

// Task/action types differ from UnitAIModule action IDs and command packet IDs.
#define RGE_ACTION_TYPE_MOVE       1
#define RGE_ACTION_TYPE_ENTER      3
#define RGE_ACTION_TYPE_EXPLORE    4
#define RGE_ACTION_TYPE_GATHER     5
#define RGE_ACTION_TYPE_MISSILE    8
#define RGE_ACTION_TYPE_ATTACK     9
#define RGE_ACTION_TYPE_BIRD       10
#define RGE_ACTION_TYPE_TRANSPORT  0x0C
#define RGE_ACTION_TYPE_RUN_AWAY   20
#define RGE_ACTION_TYPE_MAKE       0x15
#define TRIBE_ACTION_TYPE_BUILD               0x65
#define TRIBE_ACTION_TYPE_MAKE_OBJECT         0x66
#define TRIBE_ACTION_TYPE_MAKE_TECH           0x67
#define TRIBE_ACTION_TYPE_CONVERT             0x68
#define TRIBE_ACTION_TYPE_HEAL                0x69
#define TRIBE_ACTION_TYPE_REPAIR              0x6A
#define TRIBE_ACTION_TYPE_ARTIFACT            0x6B
#define TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT  0x6C
#define TRIBE_ACTION_TYPE_HUNT                0x6E
#define TRIBE_ACTION_TYPE_TRADE               0x6F
#define TRIBE_ACTION_TYPE_WONDER              0x78

// Update results differ from action states and object-update results.
// RGE_Action_List::update removes on REMOVE, not COMPLETED.
#define RGE_ACTION_UPDATE_CONTINUE        0
#define RGE_ACTION_UPDATE_REMOVE          1
#define RGE_ACTION_UPDATE_COMPLETED       2
#define RGE_ACTION_UPDATE_FAILED          3
#define RGE_ACTION_UPDATE_TARGET_INVALID  4
// Attack also returns TARGET_LOST after its sub-action completion animation clears the target.
#define RGE_ACTION_UPDATE_TARGET_LOST     5

class RGE_Action_List;
class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Task_List;

// action.cpp owns this 0x40-byte base class.
// Derived action modules must use this virtual order.
class RGE_Action {
public:
    RGE_Action();
    RGE_Action(int infile, RGE_Action_Object* obj_in, int do_setup);
    RGE_Action(RGE_Action_Object* obj_in, int do_setup);

    virtual ~RGE_Action();
    virtual int setup(int infile, RGE_Action_Object* obj_in);
    virtual int setup(RGE_Action_Object* obj_in);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* obj_in);
    virtual void rehook();
    virtual void save(int outfile);
    virtual short type();
    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* obj_in);
    virtual unsigned char relation_response(long player_id, unsigned char relation);
    virtual void copy_obj(RGE_Master_Action_Object* source);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task,
                                  RGE_Task* new_task);
    virtual void get_state_name(char* state_name);
    virtual RGE_Static_Object* get_target_obj() { return this->target_obj; }
    virtual RGE_Static_Object* get_target_obj2() { return this->target_obj2; }
    virtual void set_target_obj(RGE_Static_Object* new_obj);
    virtual void set_target_obj2(RGE_Static_Object* new_obj);

protected:
    virtual void set_state(unsigned char new_state);

public:
    short action_type;
    RGE_Action_Object* obj;
    unsigned char state;
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

    unsigned char subAction() const;
    void setSubAction(unsigned char v);
    float targetX() const;
    float targetY() const;
    float targetZ() const;
};

typedef char action_size_check[(sizeof(RGE_Action) == 0x40) ? 1 : -1];

#endif
