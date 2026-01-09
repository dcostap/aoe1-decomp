#pragma once
#include "common.h"

class RGE_Action_Enter : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x402600
    virtual uchar update();                                 // vt0[10]+0x28=0x402740
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x402610
    RGE_Action_Enter(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    ~RGE_Action_Enter();
};

static_assert(sizeof(RGE_Action_Enter) == 0x40, "RGE_Action_Enter Size Mismatch");

