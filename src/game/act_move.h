#pragma once
#include "../common.h"
#include "action.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;                             // 0x40

    RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6);
    RGE_Action_Move_To(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, RGE_Sprite* param_4);
    virtual ~RGE_Action_Move_To();
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual uchar is_in_range();
};

static_assert(sizeof(RGE_Action_Move_To) == 0x44, "RGE_Action_Move_To Size Mismatch");
static_assert(offsetof(RGE_Action_Move_To, range) == 0x40, "RGE_Action_Move_To Offset Mismatch");

