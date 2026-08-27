#ifndef AOE1_ACT_ENTR_H
#define AOE1_ACT_ENTR_H

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

// act_entr.cpp owns this empty 0x40-byte RGE_Action-derived class.
class RGE_Action_Enter : public RGE_Action {
public:
    RGE_Action_Enter(int, RGE_Action_Object*);
    RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);

    virtual ~RGE_Action_Enter();
    virtual void first_in_stack(unsigned char);

protected:
    virtual void set_state(unsigned char);

public:
    virtual unsigned char update();
};

typedef char rge_action_enter_size_check[
    (sizeof(RGE_Action_Enter) == 0x40) ? 1 : -1];

#endif
