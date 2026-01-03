#pragma once
#include "../common.h"
#include "action.h"
#include "act_obj.h"
#include "task.h"
#include "stat_obj.h"

class RGE_Action_Missile : public RGE_Action {
public:
    float velocity_x;                        // 0x40
    float velocity_y;                        // 0x44
    float velocity_z;                        // 0x48
    float ballistic_velocity;                // 0x4C
    float ballistic_acceleration;            // 0x50

    RGE_Action_Missile(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Missile();
    RGE_Action_Missile(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3, float param_4, float param_5, float param_6);
    virtual void first_in_stack(uchar param_1);
    virtual void intercept(float* param_1, float* param_2, float* param_3);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual void save(int param_1);
};

static_assert(sizeof(RGE_Action_Missile) == 0x54, "RGE_Action_Missile Size Mismatch");
static_assert(offsetof(RGE_Action_Missile, ballistic_acceleration) == 0x50, "RGE_Action_Missile Offset Mismatch");

