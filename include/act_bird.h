#ifndef AOE1_ACT_BIRD_H
#define AOE1_ACT_BIRD_H

#include "action.h"

class RGE_Action_Object;
class RGE_Task;

class RGE_Action_Bird : public RGE_Action {
public:
    RGE_Action_Bird(int, RGE_Action_Object*);
    RGE_Action_Bird(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();

protected:
    virtual void set_state(unsigned char);
};

typedef char rge_action_bird_size_check[
    (sizeof(RGE_Action_Bird) == 0x40) ? 1 : -1];

#endif  // AOE1_ACT_BIRD_H
