#pragma once
#include "../common.h"

class TRIBE_Action_Convert : public RGE_Action {
public:
    uchar was_same_owner;                    // 0x40
    float requiredRange;                     // 0x44

    TRIBE_Action_Convert(int param_1, RGE_Action_Object* param_2);
    virtual ~TRIBE_Action_Convert();
    TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void martyrdom();
};

static_assert(sizeof(TRIBE_Action_Convert) == 0x48, "TRIBE_Action_Convert Size Mismatch");
static_assert(offsetof(TRIBE_Action_Convert, requiredRange) == 0x44, "TRIBE_Action_Convert Offset Mismatch");

