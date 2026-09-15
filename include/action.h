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
    RGE_Action(int infile, RGE_Action_Object* obj_in, int do_setup);
    RGE_Action(RGE_Action_Object* obj_in, int do_setup);

    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* obj_in);
    virtual int setup(int infile, RGE_Action_Object* obj_in);
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
