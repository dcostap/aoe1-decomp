#ifndef AOE1_ACT_OBJ_H
#define AOE1_ACT_OBJ_H

#include "move_obj.h"

class RGE_Action;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Task;

class RGE_Action_Object : public RGE_Moving_Object {
public:
    RGE_Action_Object(RGE_Master_Action_Object*, RGE_Player*, float, float,
                      float, int);
    RGE_Action_Object(int, RGE_Game_World*, int);

    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void rehook();
    virtual void save(int);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void destroy_obj();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float,
                       unsigned char);
    virtual unsigned char update();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual RGE_Master_Static_Object* get_command_master(
        RGE_Static_Object*, float, float, float);
    virtual void set_task(short);
    void setTaskByTaskID(int);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    void set_end_action(RGE_Action*);
    virtual void stop();
    virtual void change_ownership(RGE_Player*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);

protected:
    virtual int setup(RGE_Master_Action_Object*, RGE_Player*, float, float,
                      float);
    virtual int setup(int, RGE_Game_World*);
    virtual RGE_Action_List* create_action_list();

public:
    virtual unsigned char actionState() const;
    virtual long get_action_checksum();

    unsigned char waiting;
    RGE_Action_List* actions;
    unsigned char command_flag;
    int lastActionValue;
    int lastActionStateValue;

    unsigned char have_action();
};

typedef char rge_action_object_size_check[
    (sizeof(RGE_Action_Object) == 0x194) ? 1 : -1];

#endif
