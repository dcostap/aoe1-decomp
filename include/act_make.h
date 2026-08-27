#ifndef AOE1_ACT_MAKE_H
#define AOE1_ACT_MAKE_H

#include "action.h"

class RGE_Action_Object;
class RGE_Task;

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(int, RGE_Action_Object*);
    RGE_Action_Make(RGE_Action_Object*, RGE_Task*);

    virtual ~RGE_Action_Make();
    virtual void first_in_stack(unsigned char);

protected:
    virtual void set_state(unsigned char);

public:
    virtual unsigned char update();
};

typedef char rge_action_make_size_check[
    (sizeof(RGE_Action_Make) == 0x40) ? 1 : -1];

#endif
