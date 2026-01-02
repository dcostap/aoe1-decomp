#pragma once
#include "../common.h"

class TRIBE_Action_Wonder : public RGE_Action {
public:

    TRIBE_Action_Wonder(int param_1, RGE_Action_Object* param_2);
    TRIBE_Action_Wonder(RGE_Action_Object* param_1);
    virtual ~TRIBE_Action_Wonder();
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
};

static_assert(sizeof(TRIBE_Action_Wonder) == 0x40, "TRIBE_Action_Wonder Size Mismatch");

