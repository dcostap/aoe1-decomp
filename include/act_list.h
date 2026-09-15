#ifndef AOE1_ACT_LIST_H
#define AOE1_ACT_LIST_H

#include "action.h"

class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int infile, short action_type);
    virtual RGE_Action* create_task_action(RGE_Task* task, RGE_Static_Object* target_obj,
                                           float target_x, float target_y, float target_z);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
    virtual void get_action_name(char* action_name);
    virtual void copy_obj(RGE_Master_Action_Object* source);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task,
                                  RGE_Task* new_task);

    RGE_Action_List(RGE_Action_Object* obj_in);
    ~RGE_Action_List();

    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void load(int infile);
    void rehook();
    void save(int outfile);
    void delete_list();
    void add_action(RGE_Action* action);
    void add_action_at_end(RGE_Action* action);
    void add_action_at_end_of_action_queue(RGE_Action* action);
    void remove_action();
    unsigned char have_action();
    int action_stop();
    int action_move_to(RGE_Static_Object* obj_in, float x, float y, float z);
    int action_work(RGE_Static_Object* obj_in, float x, float y, float z);
    int attack_response(RGE_Static_Object* attacker);
    int relation_response(long player_id, unsigned char relation);
    RGE_Action* get_action();
    RGE_Task* get_task();
};

typedef char action_list_size_check[
    (sizeof(RGE_Action_List) == 0x0C) ? 1 : -1];

#endif
