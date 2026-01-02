#pragma once
#include "../common.h"

class RGE_Action_Bird : public RGE_Action {
public:

    RGE_Action_Bird(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Bird();
    RGE_Action_Bird(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
};

static_assert(sizeof(RGE_Action_Bird) == 0x40, "RGE_Action_Bird Size Mismatch");

