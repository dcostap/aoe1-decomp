#pragma once
#include "common.h"

class RGE_Action_Make : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x404A40
    virtual uchar update();                                 // vt0[10]+0x28=0x404A90
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x404A70
    RGE_Action_Make(int param_1, RGE_Action_Object* param_2);
    ~RGE_Action_Make();
    RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2);
};

static_assert(sizeof(RGE_Action_Make) == 0x40, "RGE_Action_Make Size Mismatch");

