#ifndef AOE1_TASK_LST_H
#define AOE1_TASK_LST_H

#include "task.h"

class RGE_Sprite;
class RGE_Sound;
class RGE_Action_Object;
class RGE_Static_Object;

typedef char task_lst_task_size_check[(sizeof(RGE_Task) == 0x4C) ? 1 : -1];

class RGE_Task_List {
public:
    RGE_Task_List();
    // The destructor is nonvirtual in the original ABI.
    ~RGE_Task_List();

    void copy(RGE_Task_List*);
    void load(int, RGE_Sprite**, RGE_Sound**);
    void load(FILE*, RGE_Sprite**, RGE_Sound**);
    void save(int);
    void delete_list();

    virtual RGE_Task* create_task(short, short);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
    virtual int is_attack_task(RGE_Task*);

protected:
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);

public:
    RGE_Task** list;
    short list_num;
};

typedef char task_lst_task_list_size_check[(sizeof(RGE_Task_List) == 0x0C) ? 1 : -1];

#endif
