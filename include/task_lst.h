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

    void copy(RGE_Task_List* other_list);
    void load(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    void load(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    void save(int outfile);
    void delete_list();

    virtual RGE_Task* create_task(short task_type, short index);
    virtual RGE_Task* get_target_task(
        RGE_Action_Object* obj, RGE_Static_Object* target_obj, float target_x, float target_y, float target_z
    );
    virtual int is_attack_task(RGE_Task* task);

  protected:
    virtual int check_task(RGE_Task* task, RGE_Action_Object* obj, RGE_Static_Object* target_obj);

  public:
    RGE_Task** list;
    short list_num;
};

typedef char task_lst_task_list_size_check[(sizeof(RGE_Task_List) == 0x0C) ? 1 : -1];

#endif
