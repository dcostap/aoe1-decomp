#pragma once
#include "../common.h"
#include "action.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"

class RGE_Action_Make : public RGE_Action {
public:

    RGE_Action_Make(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Make();
    RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
};

static_assert(sizeof(RGE_Action_Make) == 0x40, "RGE_Action_Make Size Mismatch");

