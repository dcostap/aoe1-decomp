#ifndef AOE1_ACT_EXPL_H
#define AOE1_ACT_EXPL_H

#include "action.h"

class RGE_Action_Object;
class RGE_Task;

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(int infile, RGE_Action_Object* obj_in);
    RGE_Action_Explore(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);

    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);

protected:
    virtual void set_state(unsigned char new_state);
};

typedef char rge_action_explore_size_check[
    (sizeof(RGE_Action_Explore) == 0x40) ? 1 : -1];

#endif  // AOE1_ACT_EXPL_H
