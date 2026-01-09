#pragma once
#include "common.h"

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;                             // 0x40

    virtual void save(int param_1);                         // vt0[5]+0x14=0x405750
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x405780
    virtual uchar update();                                 // vt0[10]+0x28=0x405850
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4057E0
    RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6);
    RGE_Action_Move_To(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, RGE_Sprite* param_4);
    ~RGE_Action_Move_To();
    uchar is_in_range();
};

static_assert(sizeof(RGE_Action_Move_To) == 0x44, "RGE_Action_Move_To Size Mismatch");

