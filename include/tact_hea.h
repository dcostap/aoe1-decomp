#ifndef AOE1_TACT_HEA_H
#define AOE1_TACT_HEA_H

#include "action.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;

class TRIBE_Action_Heal : public RGE_Action {
public:
    TRIBE_Action_Heal(int, RGE_Action_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
};

typedef char tact_hea_action_size[
    (sizeof(TRIBE_Action_Heal) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_HEA_H
