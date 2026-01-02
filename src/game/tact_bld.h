#pragma once
#include "../common.h"

class TRIBE_Action_Build : public RGE_Action {
public:

    TRIBE_Action_Build(int param_1, RGE_Action_Object* param_2);
    virtual ~TRIBE_Action_Build();
    TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

static_assert(sizeof(TRIBE_Action_Build) == 0x40, "TRIBE_Action_Build Size Mismatch");

