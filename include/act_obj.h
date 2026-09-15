#ifndef AOE1_ACT_OBJ_H
#define AOE1_ACT_OBJ_H

#include "move_obj.h"

class RGE_Action;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Task;

class RGE_Action_Object : public RGE_Moving_Object {
public:
    RGE_Action_Object(RGE_Master_Action_Object* tobj, RGE_Player* obj_owner, float x, float y,
                      float z, int do_setup);
    RGE_Action_Object(int infile, RGE_Game_World* gworld, int do_setup);

    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner,
                                    float x, float y, float z);
    virtual void recycle_out_of_game();
    virtual void rehook();
    virtual void save(int outfile);
    virtual void transform(RGE_Master_Static_Object* obj);
    virtual void destroy_obj();
    virtual void notify_of_relation(long player_id, unsigned char relation);
    virtual void do_command(RGE_Static_Object* obj, float x, float y, float z);
    virtual void move_to(RGE_Static_Object* obj, float x, float y, float z);
    virtual void work(RGE_Static_Object* obj, float x, float y, float z);
    virtual void work2(RGE_Static_Object* obj, float x, float y, float z, unsigned char work_flag);
    virtual unsigned char update();
    virtual void set_attack(RGE_Static_Object* obj);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* obj, float x, float y, float z);
    virtual void set_task(short task_id);
    virtual void setTaskByTaskID(int t);
    virtual void set_action(RGE_Action* action);
    virtual void set_only_action(RGE_Action* action);
    virtual void set_end_action(RGE_Action* action);
    virtual void stop();
    virtual void change_ownership(RGE_Player* new_owner);
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Task* getTask(RGE_Static_Object* target, float targetX, float targetY, float targetZ);

protected:
    virtual int setup(RGE_Master_Action_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
    virtual int setup(int infile, RGE_Game_World* gworld);
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
