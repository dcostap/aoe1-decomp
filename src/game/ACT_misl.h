#pragma once
#include "common.h"

class RGE_Action_Missile : public RGE_Action {
public:
    float velocity_x;                        // 0x40
    float velocity_y;                        // 0x44
    float velocity_z;                        // 0x48
    float ballistic_velocity;                // 0x4C
    float ballistic_acceleration;            // 0x50

    virtual void save(int param_1);                         // vt0[5]+0x14=0x4054B0
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x404D10
    virtual uchar update();                                 // vt0[10]+0x28=0x4050F0
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x404DB0
    RGE_Action_Missile(int param_1, RGE_Action_Object* param_2);
    ~RGE_Action_Missile();
    RGE_Action_Missile(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3, float param_4, float param_5, float param_6);
    void intercept(float* param_1, float* param_2, float* param_3);
};

static_assert(sizeof(RGE_Action_Missile) == 0x54, "RGE_Action_Missile Size Mismatch");

