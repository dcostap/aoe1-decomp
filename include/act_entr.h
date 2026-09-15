#ifndef AOE1_ACT_ENTR_H
#define AOE1_ACT_ENTR_H

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

// act_entr.cpp owns this empty 0x40-byte RGE_Action-derived class.
class RGE_Action_Enter : public RGE_Action {
public:
    RGE_Action_Enter(int infile, RGE_Action_Object* obj_in);
    RGE_Action_Enter(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);

    virtual ~RGE_Action_Enter();
    virtual void first_in_stack(unsigned char first_time);

protected:
    virtual void set_state(unsigned char new_state);

public:
    virtual unsigned char update();
};

typedef char rge_action_enter_size_check[
    (sizeof(RGE_Action_Enter) == 0x40) ? 1 : -1];

#endif
