#pragma once
#include "common.h"

class TRIBE_Action_Wonder : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4D3690
    virtual uchar update();                                 // vt0[10]+0x28=0x4D3810
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4D36B0
    TRIBE_Action_Wonder(int param_1, RGE_Action_Object* param_2);
    TRIBE_Action_Wonder(RGE_Action_Object* param_1);
    ~TRIBE_Action_Wonder();
};

static_assert(sizeof(TRIBE_Action_Wonder) == 0x40, "TRIBE_Action_Wonder Size Mismatch");

