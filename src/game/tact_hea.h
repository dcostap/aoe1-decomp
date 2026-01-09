#pragma once
#include "common.h"

class TRIBE_Action_Heal : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4CEA50
    virtual uchar update();                                 // vt0[10]+0x28=0x4CECF0
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x4CF030
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4CEA90
    TRIBE_Action_Heal(int param_1, RGE_Action_Object* param_2);
    ~TRIBE_Action_Heal();
    TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

static_assert(sizeof(TRIBE_Action_Heal) == 0x40, "TRIBE_Action_Heal Size Mismatch");

