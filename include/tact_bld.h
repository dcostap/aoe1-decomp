#ifndef AOE1_TACT_BLD_H
#define AOE1_TACT_BLD_H

#include "action.h"

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(int, RGE_Action_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual void first_in_stack(unsigned char);

protected:
    virtual void set_state(unsigned char);

public:
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
};

typedef char tact_bld_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_bld_build_size[
    (sizeof(TRIBE_Action_Build) == 0x40) ? 1 : -1];

#endif  // AOE1_TACT_BLD_H
