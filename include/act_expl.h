#ifndef AOE1_ACT_EXPL_H
#define AOE1_ACT_EXPL_H

#include "action.h"

class RGE_Action_Object;
class RGE_Task;

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(int, RGE_Action_Object*);
    RGE_Action_Explore(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
};

typedef char rge_action_explore_size_check[
    (sizeof(RGE_Action_Explore) == 0x40) ? 1 : -1];

#endif  // AOE1_ACT_EXPL_H
