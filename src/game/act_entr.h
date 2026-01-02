#pragma once
#include "../common.h"

class RGE_Action_Enter : public RGE_Action {
public:

    RGE_Action_Enter(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    virtual ~RGE_Action_Enter();
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
};

static_assert(sizeof(RGE_Action_Enter) == 0x40, "RGE_Action_Enter Size Mismatch");

