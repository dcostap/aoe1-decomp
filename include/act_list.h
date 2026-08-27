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
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*,
                                            float, float, float);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
    virtual void get_action_name(char*);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*,
                                  RGE_Task*);

    RGE_Action_List(RGE_Action_Object*);
    ~RGE_Action_List();

    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void load(int);
    void rehook();
    void save(int);
    void delete_list();
    void add_action(RGE_Action*);
    void add_action_at_end(RGE_Action*);
    void add_action_at_end_of_action_queue(RGE_Action*);
    void remove_action();
    unsigned char have_action();
    int action_stop();
    int action_move_to(RGE_Static_Object*, float, float, float);
    int action_work(RGE_Static_Object*, float, float, float);
    int attack_response(RGE_Static_Object*);
    int relation_response(long, unsigned char);
    RGE_Action* get_action();
    RGE_Task* get_task();
};

typedef char action_list_size_check[
    (sizeof(RGE_Action_List) == 0x0C) ? 1 : -1];

#endif
