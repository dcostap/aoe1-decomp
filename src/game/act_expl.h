#pragma once
#include "../common.h"
#include "action.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"

class RGE_Action_Explore : public RGE_Action {
public:

    RGE_Action_Explore(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Explore();
    RGE_Action_Explore(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

static_assert(sizeof(RGE_Action_Explore) == 0x40, "RGE_Action_Explore Size Mismatch");

