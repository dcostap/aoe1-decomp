#pragma once
#include "common.h"

class RGE_Action_Explore : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x402BE0
    virtual uchar update();                                 // vt0[10]+0x28=0x402D90
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x402E40
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x402C00
    RGE_Action_Explore(int param_1, RGE_Action_Object* param_2);
    ~RGE_Action_Explore();
    RGE_Action_Explore(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

static_assert(sizeof(RGE_Action_Explore) == 0x40, "RGE_Action_Explore Size Mismatch");

