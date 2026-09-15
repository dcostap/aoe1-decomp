#ifndef AOE1_ACT_MAKE_H
#define AOE1_ACT_MAKE_H

#include "action.h"

class RGE_Action_Object;
class RGE_Task;

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(int infile, RGE_Action_Object* obj_in);
    RGE_Action_Make(RGE_Action_Object* obj_in, RGE_Task* task_in);

    virtual void first_in_stack(unsigned char first_time);

protected:
    virtual void set_state(unsigned char new_state);

public:
    virtual unsigned char update();
};

typedef char rge_action_make_size_check[
    (sizeof(RGE_Action_Make) == 0x40) ? 1 : -1];

#endif
