#ifndef AOE1_ACTION_H
#define AOE1_ACTION_H

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
    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);

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
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*,
                                  RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);

protected:
    virtual void set_state(unsigned char);

public:
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
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    unsigned char gap_3D[3];

    unsigned char subAction() const;
    void setSubAction(unsigned char);
    float targetX() const;
    float targetY() const;
    float targetZ() const;
};

typedef char action_size_check[(sizeof(RGE_Action) == 0x40) ? 1 : -1];

#endif
