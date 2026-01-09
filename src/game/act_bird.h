#pragma once
#include "common.h"

class RGE_Action_Bird : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x402080
    virtual uchar update();                                 // vt0[10]+0x28=0x402180
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4020C0
    RGE_Action_Bird(int param_1, RGE_Action_Object* param_2);
    ~RGE_Action_Bird();
    RGE_Action_Bird(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

static_assert(sizeof(RGE_Action_Bird) == 0x40, "RGE_Action_Bird Size Mismatch");

